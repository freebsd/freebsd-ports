PORTNAME=	gimp
DISTVERSION=	2.10.38
PORTEPOCH=	2
CATEGORIES=	graphics gnome
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Meta-port for the Gimp
WWW=		https://www.gimp.org/

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	multi

RUN_DEPENDS=	gimp-2.10:graphics/gimp-app

USES=		metaport

NO_ARCH=	yes
NO_BUILD=	yes

OPTIONS_DEFINE=		PRINT
OPTIONS_DEFAULT=	PRINT
PRINT_DESC=		Gutenprint (gimp-print) plugin

PRINT_RUN_DEPENDS=	${LOCALBASE}/libexec/gimp/2.2/plug-ins/gutenprint:print/gimp-gutenprint \
			gutenprint>0:print/gutenprint

.include <bsd.port.mk>
