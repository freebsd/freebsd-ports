# New ports collection makefile for:	metakit
# Date created:		25 December 1999
# Whom:			Russell L. Carter <rcarter@pinyon.org>
#
# $FreeBSD$
#

PORTNAME=	metakit
PORTVERSION=	2.4.2
PORTREVISION=	32
CATEGORIES=	databases python
MASTER_SITES=	http://www.equi4.com/pub/mk/
DISTNAME=	${PORTNAME}-${PORTVERSION}-${PORTREVISION}

MAINTAINER=	dinoex@FreeBSD.org

.if !defined(METAKIT_WITHOUT_PYTHON)
BUILD_DEPENDS=	python1.5:${PORTSDIR}/lang/python15
RUN_DEPENDS=	python1.5:${PORTSDIR}/lang/python15
.endif
.if defined(METAKIT_WITH_TCL)
LIB_DEPENDS=	tcl83.1:${PORTSDIR}/lang/tcl83
.endif
.if defined(METAKIT_WITH_TCLKIT)
LIB_DEPENDS=	tcl84.1:${PORTSDIR}/lang/tcl84
BUILD_DEPENDS=	wish8.4:${PORTSDIR}/x11-toolkits/tk84
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
CONFIGURE_ARGS+=	--with-tcl=${LOCALBASE}/include/tcl${TCL_V}
CATEGORIES+=	tcl83
TCL_V=		8.3
TCL_SHORT_V=	83
PLIST_SUB+=	WITH_TCL=""
.else
PLIST_SUB+=	WITH_TCL="@comment "
.endif

.if defined(METAKIT_WITH_TCLKIT)
CONFIGURE_ARGS+=	--with-tcl=${LOCALBASE}/include/tcl${TCL_V}
TCL_V=		8.4
TCL_SHORT_V=	84
MAKE_ENV+=	V=${TCL_V} SHORT_V=${TCL_SHORT_V}
PLIST_SUB+=	WITH_TCLKIT=""
.else
PLIST_SUB+=	WITH_TCLKIT="@comment "
.endif

pre-patch:
	@${PERL5} -pi -e "s/= tclsh/=tclsh${TCL_V}/" \
		${WRKSRC}/../unix/Makefile.in
	@${PERL5} -pi -e "s=doc/==" ${WRKSRC}/../MetaKit.html

post-install:
.if !defined(METAKIT_WITHOUT_PYTHON)
	@${INSTALL_PROGRAM} ${WRKSRC}/Mk4py.so \
		${PREFIX}/lib/python1.5/site-packages
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/metakit
	(${TAR} -C ${WRKSRC}/../doc -cf - . | \
		${TAR} -C ${PREFIX}/share/doc/metakit --unlink -xf -)
	${INSTALL_DATA} ${WRKSRC}/../MetaKit.html ${WRKSRC}/../CHANGES \
		${WRKSRC}/../README ${WRKSRC}/../WHATSNEW \
		${PREFIX}/share/doc/metakit
.endif

test:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
	${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} test)
.if defined(METAKIT_WITH_TCL) || defined(METAKIT_WITH_TCLKIT)
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
	${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} test-tcl)
.endif

.include <bsd.port.mk>
