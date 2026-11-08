PORTNAME=	xdr
PORTVERSION=	3.0.3
PORTREVISION=	3
CATEGORIES=	converters rubygems
MASTER_SITES=	RG

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	XDR Helper Library
WWW=		https://github.com/stellar/ruby-xdr

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-activemodel80>=8.0:databases/rubygem-activemodel80 \
		rubygem-activesupport80>=8.0:devel/rubygem-activesupport80

USES=		gem

NO_ARCH=	yes

post-patch:
# The upper bound is precautionary, the gem only uses basic ActiveSupport
# and ActiveModel features.  Rails 8 is what security/metasploit needs.
	@${REINPLACE_CMD} -e 's|"< 8.0"|"< 9.0"|' ${WRKSRC}/${GEMSPEC}

.include <bsd.port.mk>
