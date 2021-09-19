PORTNAME=	libnuml
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.4
CATEGORIES=	biology devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ library for Numerical Markup Language

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
	@${RM} -r ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
