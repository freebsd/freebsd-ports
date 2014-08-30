# Created by: Nick Sayer <nsayer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	unixODBC
PORTVERSION=	2.3.2
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://www.unixodbc.org/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ODBC library suite for Unix

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

OPTIONS_DEFINE=	DOCS

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_header_msql_h=no
CONFIGURE_ARGS=	--enable-static --enable-shared \
		${ICONV_CONFIGURE_ARG}
INSTALL_TARGET=	install-strip
# :keepla because port uses lt_dlopen
USES=		iconv libtool:keepla
USE_LDCONFIG=	yes

PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} -e \
		'/\.ini/s|^|#|' ${WRKSRC}/Makefile.in

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}
	@${FIND} ${STAGEDIR}${DOCSDIR} -type f -name "*Makefile*" -delete

.include <bsd.port.mk>
