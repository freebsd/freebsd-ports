# New ports collection makefile for:	cvsgraph
# Date created:				2001-02-21
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	cvsgraph
PORTVERSION=	1.4.0
PORTREVISION=	1
CATEGORIES=	devel graphics
MASTER_SITES=	http://www.akhphd.au.dk/~bertho/cvsgraph/release/

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	Graph the life story of a file under CVS or RCS

LIB_DEPENDS=	gd.4:${PORTSDIR}/graphics/gd \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAN1=		cvsgraph.1
MAN5=		cvsgraph.conf.5

USE_BISON=	yes
ALL_TARGET=	cvsgraph
DOCDIR=		share/doc/${PORTNAME}
DOCS=		ChangeLog LICENSE README
EXAMPLES=	cvsgraphwrapper.php3 mkimage.php3
NOT_FOR_ARCHS=	alpha amd64
PLIST=		${WRKDIR}/pkg-plist
USE_AUTOCONF=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-freetype2-inc=${X11BASE}/include/freetype2/freetype \
		--with-freetype2-lib=${X11BASE}/lib \
		--with-gd-inc=${LOCALBASE}/include \
		--with-gd-lib=${LOCALBASE}/lib \
		--with-jpeg-inc=${LOCALBASE}/include \
		--with-jpeg-lib=${LOCALBASE}/lib \
		--with-png-inc=${LOCALBASE}/include \
		--with-png-lib=${LOCALBASE}/lib \
		--with-z-inc=/usr/include \
		--with-z-lib=/usr/lib \
		--with-freetype2 \
		--with-gd \
		--with-jpeg \
		--with-png \
		--with-z

pre-patch:
	${RM} ${WRKSRC}/configure # Avoid having to read this file.
	${MV} ${WRKSRC}/cvsgraph.conf ${WRKSRC}/cvsgraph.conf.orig
	${SED} -e "s:/home/bertho/tmp/cvstest:/home/ncvs:g" \
		< ${WRKSRC}/cvsgraph.conf.orig > ${WRKSRC}/cvsgraph.conf

post-configure:
	${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.orig
	${SED} -e "s|CFLAGS	=|CFLAGS += -I${LOCALBASE}/include \
		-I${LOCALBASE}/include/gd|g" \
		< ${WRKSRC}/Makefile.orig > ${WRKSRC}/Makefile

pre-install:
	${ECHO_CMD} bin/cvsgraph > ${PLIST}
	${ECHO_CMD} etc/cvsgraph.conf >> ${PLIST}
.if !defined(NOPORTDOCS)
.for i in ${DOCS}
	${ECHO_CMD} ${DOCDIR}/${i} >> ${PLIST}
.endfor
.for i in ${EXAMPLES}
	${ECHO_CMD} share/examples/${PORTNAME}/${i} >> ${PLIST}
.endfor
	${ECHO_CMD} @dirrm share/examples/${PORTNAME} >> ${PLIST}
	${ECHO_CMD} @dirrm ${DOCDIR} >> ${PLIST}
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/cvsgraph.conf ${PREFIX}/etc
	${INSTALL_MAN} ${WRKSRC}/cvsgraph.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/cvsgraph.conf.5 ${PREFIX}/man/man5
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/${DOCDIR}
	${MKDIR} ${PREFIX}/share/examples/${PORTNAME}
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/${DOCDIR}
.endfor
.for i in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/share/examples/${PORTNAME}
.endfor
.endif

.include <bsd.port.mk>
