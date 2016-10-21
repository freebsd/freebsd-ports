# Created by: David O'Brien <obrien@NUXI.com>
# $FreeBSD$

PORTNAME=	ddd
PORTVERSION=	3.3.12
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	GNU

MAINTAINER=	sergio@softshark.org
COMMENT=	Data Display Debugger -- a common graphical front-end for GDB/DBX/XDB

USES=		cpe gmake makeinfo motif
USE_XORG=	xpm
GNU_CONFIGURE=	yes

CFLAGS+=	-Wno-deprecated
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-motif-libraries="${LIBXMDIR}" \
		--with-readline-libraries=/usr/lib

PLIST_SUB=	VERSION=${PORTVERSION}

DOCS=		AUTHORS INSTALL PROBLEMS README TIPS TODO \
		doc/html/ddd.html doc/ddd-paper.ps \
		doc/ddd-themes.pdf doc/ddd.pdf
INFO=		ddd ddd-themes
CPE_PRODUCT=	data_display_debugger
CPE_VENDOR=	gnu

OPTIONS_DEFINE=	DOCS

.if defined(MOTIFLIB)
.if defined(MOTIF_STATIC)
LIBXMDIR!=	${ECHO_CMD} ${MOTIFLIB} | ${SED} -e 's/\/libXm\.a//g' | ${AWK} '{print $$1}'
.else
LIBXMDIR!=	${ECHO_CMD} ${MOTIFLIB} | ${SED} -e 's/-L//g' | ${AWK} '{print $$1}'
.endif
.else
LIBXMDIR=	${LOCALBASE}
.endif

pre-patch:
	@${RM}v ${WRKSRC}/ddd/ddd.info*
	@${RM}v ${WRKSRC}/ddd/ddd-themes.info*

pre-configure:
	@${FIND} ${WRKSRC} -name configure | ${XARGS} \
		${REINPLACE_CMD} -e "s|-O2||"

post-configure:
	@${ECHO_CMD} "LIBXM = ${MOTIFLIB}" >> ${WRKSRC}/ddd/Makefile

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor
	${GZIP_CMD} ${STAGEDIR}${DOCSDIR}/*.ps

check:
	(cd ${WRKSRC} ; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} check)

.include <bsd.port.mk>
