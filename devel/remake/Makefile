# Created by: arved
# $FreeBSD$

PORTNAME=	remake
PORTVERSION=	1.5
CATEGORIES=	devel
MASTER_SITES=	SF/bashdb/remake/4.3+dbg-${PORTVERSION}/
DISTNAME=	remake-4.3+dbg-${PORTVERSION}

MAINTAINER=	arved@FreeBSD.org
COMMENT=	Fork of gmake with debugger

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
USES=		readline
INFO=		remake
CONFIGURE_ARGS=	--without-guile

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext iconv
NLS_CONFIGURE_ON=	${ICONV_CONFIGURE_ARG} \
			--with-libintl-prefix=${LOCALBASE}
NLS_CONFIGURE_ENABLE=	nls

post-patch:
	${REINPLACE_CMD} -e "s,remake.info make.info,remake.info,; \
		s,make.info remake.info,remake.info," \
		${WRKSRC}/doc/Makefile.in

.include <bsd.port.mk>
