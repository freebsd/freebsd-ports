# Created by: Johann Visagie <wjv@FreeBSD.org>
# $FreeBSD$

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

OPTIONS_DEFINE=	WXGTK DOCS

WRKSRC=		${WRKDIR}/${DISTNAME:S,${DISTVERSIONSUFFIX},,}

GNU_CONFIGURE=	yes

PORTDOCS=	*
PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MWXGTK}
USE_WX=		2.8
WX_CONF_ARGS=	absolute
WX_UNICODE=	yes
PLIST_FILES+=	bin/lam_conv
.else
CONFIGURE_ARGS+=	--disable-converter
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|/html/lamarc|/${DOCSDIR_REL}|' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
