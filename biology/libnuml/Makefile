PORTNAME=	libnuml
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.7
PORTREVISION=	1
CATEGORIES=	biology devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ library for Numerical Markup Language
WWW=		https://github.com/NuML/NuML

LICENSE=	LGPL21

LIB_DEPENDS=	libsbml.so:biology/libsbml

USES=		cmake gnome
USE_GNOME=	libxml2
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	NuML
GH_PROJECT=	NuML

WRKSRC_SUBDIR=	${PORTNAME}

post-install:
	# no need to install LICENSE, README, VERSION
	@${RM} -r ${STAGEDIR}${DATADIR}
	# workaround for https://github.com/NuML/NuML/issues/26
	${RM} -r ${STAGEDIR}${PREFIX}/share/cmake

.include <bsd.port.mk>
