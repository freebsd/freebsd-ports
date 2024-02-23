PORTNAME=	sed
PORTVERSION=	3.62
PORTREVISION=	5
CATEGORIES=	editors textproc
MASTER_SITES=	http://sed.sourceforge.net/grabbag/ssed/
PKGNAMEPREFIX=	s

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Heavily enhanced version of sed(1)
WWW=		https://sed.sourceforge.net/grabbag/ssed/

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--program-prefix=s

OPTIONS_DEFINE=	NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext iconv
CONFIGURE_ARGS+=	${ICONV_CONFIGURE_ARG}
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.mk>
