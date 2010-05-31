# ex:ts=8
# Ports collection makefile for:  wgetpro
# Date created:			May 18, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	wgetpro
PORTVERSION=	0.1.3
PORTREVISION=	3
CATEGORIES=	ftp
MASTER_SITES=	SF
EXTRACT_SUFX=	.tgz

MAINTAINER=	stas@FreeBSD.org
COMMENT=	Wget with "PRO" features

RESTRICTED=	"may implement United States Patent 6,041,345"
USE_OPENSSL=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
PLIST_SUB+=	NLS=""
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|^\(PACKAGE=\).*|\1wpro|' ${WRKSRC}/configure

.include <bsd.port.mk>
