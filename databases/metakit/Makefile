# New ports collection makefile for:	metakit
# Date created:		25 December 1999
# Whom:			Russell L. Carter <rcarter@pinyon.org>
#
# $FreeBSD$
#

PORTNAME=	metakit
PORTVERSION=	2.4.1
PORTREVISION=	31
CATEGORIES=	databases python
MASTER_SITES=	http://www.equi4.com/pub/mk/
DISTNAME=	${PORTNAME}-${PORTVERSION}-31

MAINTAINER=	dinoex@FreeBSD.org

.if !defined(METAKIT_WITHOUT_PYTHON)
BUILD_DEPENDS=	python1.5:${PORTSDIR}/lang/python15
RUN_DEPENDS=	python1.5:${PORTSDIR}/lang/python15
.endif
.if defined(METAKIT_WITH_TCL)
LIB_DEPENDS=	tcl83.1:${PORTSDIR}/lang/tcl83
.endif

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/builds
USE_LIBTOOL=	yes
CONFIGURE_SCRIPT=	../unix/configure
LIBTOOLFILES=	${CONFIGURE_SCRIPT}
INSTALLS_SHLIB=	yes
MAKE_ARGS=	CXXFLAGS="-Dq4_INLINE ${CFLAGS} -fpermissive"

.if !defined(METAKIT_WITHOUT_PYTHON)
CONFIGURE_ARGS+=	--enable-python
CATEGORIES+=	python
PLIST_SUB+=	WITH_PYTHON=""
.else
PLIST_SUB+=	WITH_PYTHON="@comment "
.endif

.if defined(METAKIT_WITH_TCL)
CONFIGURE_ARGS+=	--with-tcl=${LOCALBASE}/lib/tcl8.3
CATEGORIES+=	tcl83
PLIST_SUB+=	WITH_TCL=""
.else
PLIST_SUB+=	WITH_TCL="@comment "
.endif

pre-patch:
	@${PERL5} -pi -e "s=\@TCL_BIN_DIR\@=${LOCALBASE}/lib=" \
		${WRKSRC}/../unix/Makefile.in
	@${PERL5} -pi -e "s=-ltclstub8.4=-ltclstub83=" \
		${WRKSRC}/../unix/Makefile.in
	@${PERL5} -pi -e "s= -Ds = -s =" \
		${WRKSRC}/../unix/Makefile.in
	@${PERL5} -pi -e "s= -D = =" \
		${WRKSRC}/../unix/Makefile.in
	@${PERL5} -pi -e \
		"s=-I..TCL_BIN_DIR.=-I${LOCALBASE}/include/tcl8.3/unix=" \
		${WRKSRC}/../unix/Makefile.in
	@${PERL5} -pi -e "s=doc/==" ${WRKSRC}/../MetaKit.html

post-install:
.if !defined(METAKIT_WITHOUT_PYTHON)
	@${INSTALL_PROGRAM} ${WRKSRC}/Mk4py.so \
		${PREFIX}/lib/python1.5/site-packages
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/metakit
	(cd ${WRKSRC}/../doc && ${TAR} -c -f - .) \
		| (cd ${PREFIX}/share/doc/metakit && ${TAR} --unlink -x -f -)
	${INSTALL_DATA} ${WRKSRC}/../MetaKit.html ${WRKSRC}/../CHANGES \
		${WRKSRC}/../README ${WRKSRC}/../WHATSNEW \
		${PREFIX}/share/doc/metakit
.endif

test:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
	${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} test)
.if defined(METAKIT_WITH_TCL)
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
	${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} test-tcl)
.endif

.include <bsd.port.mk>
