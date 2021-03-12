# Created by: UMENO Takashi
# $FreeBSD$

PORTNAME=	ninix-aya
PORTVERSION=	5.0.9
CATEGORIES=	games
MASTER_SITES=	OSDN/${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Desktop mascot program compatible with "Ukagaka"

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	rubygem-charlock_holmes>=0.7.3:textproc/rubygem-charlock_holmes \
		rubygem-gstreamer>=3.1.8:multimedia/rubygem-gstreamer \
		rubygem-gettext>=3.2.2:devel/rubygem-gettext \
		rubygem-gtk3>=3.1.8:x11-toolkits/rubygem-gtk3 \
		rubygem-narray>=0.6.1.1:math/rubygem-narray \
		rubygem-rubyzip>=1.2.1:archivers/rubygem-rubyzip

NO_ARCH=	yes
PORTDOCS=	COPYING ChangeLog README README.ninix SAORI
USES=		gettext tar:tgz
USE_RUBY=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
