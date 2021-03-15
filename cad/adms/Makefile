# Created by: Stanislav Sedov <ssedov@mbsd.msk.ru>
# $FreeBSD$

PORTNAME=	adms
PORTVERSION=	2.3.7
DISTVERSIONPREFIX=	release-
CATEGORIES=	cad

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Model generator for SPICE simulators

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-XML-LibXML>=0:textproc/p5-XML-LibXML

USES=		bison cmake perl5 # libtool
USE_GITHUB=	yes
GH_ACCOUNT=	Qucs
GH_PROJECT=	ADMS
USE_LDCONFIG=	yes

.include <bsd.port.mk>
