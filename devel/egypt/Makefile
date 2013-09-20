# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	egypt
PORTVERSION=	1.10
CATEGORIES=	devel perl5
MASTER_SITES=	http://www.gson.org/egypt/download/ CENKES

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Create call graphs of C programs

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

USES=		perl5 shebangfix
USE_PERL5=	configure
SHEBANG_FILES=	egypt

MAN1=		${PORTNAME}.1
PLIST_FILES=	bin/${PORTNAME} %%SITE_PERL%%/%%PERL_ARCH%%/auto/${PORTNAME}/.packlist
PLIST_DIRS=	%%SITE_PERL%%/%%PERL_ARCH%%/auto/${PORTNAME}

NO_STAGE=	yes
.include <bsd.port.mk>
