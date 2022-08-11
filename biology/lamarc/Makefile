PORTNAME=	lamarc
PORTVERSION=	2.1.8
DISTVERSIONSUFFIX=	-src
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	biology
MASTER_SITES=	http://evolution.genetics.washington.edu/lamarc/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Package of programs for computing population parameters

LICENSE=	APACHE20

USE_CXXSTD=	c++98

WRKSRC=		${WRKDIR}/${DISTNAME:S,${DISTVERSIONSUFFIX},,}

GNU_CONFIGURE=	yes

PORTDOCS=	*
PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=	WXGTK DOCS

WXGTK_USE=		WX=2.8
WXGTK_VARS=		WX_CONF_ARGS=absolute
WXGTK_PLIST_FILES=	bin/lam_conv
WXGTK_CONFIGURE_OFF=	--disable-converter
WXGTK_BROKEN=		does not build

post-patch:
	@${REINPLACE_CMD} -e \
		's|/html/lamarc|/${DOCSDIR_REL}|' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
