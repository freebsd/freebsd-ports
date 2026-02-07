PORTNAME=	unixODBC
PORTVERSION=	2.3.12
PORTREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	http://www.unixodbc.org/ \
		ftp://ftp.unixodbc.org/pub/unixODBC/

MAINTAINER=	brnrd@FreeBSD.org
COMMENT=	ODBC library suite for Unix
WWW=		http://www.unixodbc.org/

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

OPTIONS_DEFINE=	DOCS

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ENV=	ac_cv_header_msql_h=no
CONFIGURE_ARGS=	--enable-static --enable-shared \
		${ICONV_CONFIGURE_ARG}
INSTALL_TARGET=	install-strip
# :keepla because port uses lt_dlopen
USES=		cpe iconv libtool:keepla
USE_LDCONFIG=	yes

PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} -e 's|\.ini$$|.ini.sample|' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} \
		-e 's|/etc|${LOCALBASE}/etc|' \
		-e 's|/usr/lib|${LOCALBASE}/lib|' ${WRKSRC}/man/*.[1-9]

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} \
	    "-not -name 'Makefile*'"

.include <bsd.port.mk>
