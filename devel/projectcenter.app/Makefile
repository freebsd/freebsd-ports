# New ports collection makefile for:    ProjectCenter
# Date created:         22 Sep 2000
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	projectcenter.app
PORTVERSION=	0.3.5
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNUSTEP}
MASTER_SITE_SUBDIR=	dev-apps
DISTNAME=	ProjectCenter-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	A development environment for GNUstep

PREFIX=		${LOCALBASE}/GNUstep
NO_MTREE=	yes
WRKSRC=		${WRKDIR}/ProjectCenter
USE_GMAKE=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
MAKEFILE=	GNUmakefile
MAKE_ENV+=	ADDITIONAL_INCLUDE_DIRS="-I${WRKSRC}"
MAKE_ENV+=	ADDITIONAL_LIB_DIRS="-L${WRKSRC}/PCLib/shared_obj/${GNU_ARCH}/${OPSYS:L}/gnu-gnu-gnu"

FIXME=		GNUmakefile.bundles GNUmakefile.preamble \
		PCLib/GNUmakefile.preamble

# Quick workaround until I find out how to set the real path in the code
post-patch:
.for i in PCLib/PCBundleLoader.m PCAppController.m
	@${MV} ${WRKSRC}/${i} ${WRKSRC}/${i}.sed
	${SED} -e "s=@\"/usr/GNUstep=@\"${PREFIX}=g" \
		${WRKSRC}/${i}.sed > ${WRKSRC}/${i}
.endfor
.for i in ${FIXME}
	@${MV} ${WRKSRC}/${i} ${WRKSRC}/${i}.sed
	${SED} -e "s=-Werror==g" \
		${WRKSRC}/${i}.sed > ${WRKSRC}/${i}
.endfor

.include <bsd.port.mk>
