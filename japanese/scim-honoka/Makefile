# Created by: Masashi CHIBA
# $FreeBSD$

PORTNAME=	scim-honoka
PORTVERSION=	0.9.1
PORTREVISION=	12
CATEGORIES=	japanese
MASTER_SITES=	http://nop.net-p.org/files/honoka/
DISTNAME=	honoka-${PORTVERSION}

MAINTAINER=	chiba.masashi@gmail.com
COMMENT=	SCIM IMEngine module using various input methods

BUILD_DEPENDS=	scim:textproc/scim
RUN_DEPENDS:=	${BUILD_DEPENDS}

GNU_CONFIGURE=	yes
USES=		gettext gmake iconv libtool:keepla pathfix pkgconfig
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include -D__STDC_ISO_10646__
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} '/^LIBTOOL_EXPORT_OPTIONS=/s/=.*/=/' \
		${WRKSRC}/configure

.include <bsd.port.mk>
