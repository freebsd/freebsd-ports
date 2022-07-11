# Created by: Stanislav Sedov <ssedov@mbsd.msk.ru>

PORTNAME=	adms
PORTVERSION=	2.3.7
DISTVERSIONPREFIX=	release-
CATEGORIES=	cad

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Model generator for SPICE simulators

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	p5-XML-LibXML>=0:textproc/p5-XML-LibXML

USES=		bison cmake perl5
USE_PERL5=	build
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	Qucs
GH_PROJECT=	ADMS

PLIST_FILES=	bin/admsCheck \
		bin/admsXml \
		include/adms/constants.vams \
		include/adms/disciplines.vams \
		share/man/man1/admsCheck.1.gz \
		share/man/man1/admsXml.1.gz

.include <bsd.port.mk>
