PORTNAME=	lamarc
PORTVERSION=	2.1.8
DISTVERSIONSUFFIX=	-src
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	biology
MASTER_SITES=	http://evolution.genetics.washington.edu/lamarc/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Package of programs for computing population parameters
WWW=		https://evolution.genetics.washington.edu/lamarc/

LICENSE=	APACHE20

USE_CXXSTD=	c++98

GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${DISTNAME:S,${DISTVERSIONSUFFIX},,}

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	*

OPTIONS_DEFINE=	WXGTK DOCS

WXGTK_BROKEN=		does not build
WXGTK_USE=		WX=3.0
WXGTK_CONFIGURE_OFF=	--disable-converter
WXGTK_PLIST_FILES=	bin/lam_conv
WXGTK_VARS=		WX_CONF_ARGS=absolute

post-patch:
	@${REINPLACE_CMD} -e \
		's|/html/lamarc|/${DOCSDIR_REL}|' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
