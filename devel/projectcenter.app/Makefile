# New ports collection makefile for:    ProjectCenter
# Date created:         22 Sep 2000
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	projectcenter.app
PORTVERSION=	0.3.5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNUSTEP} \
		ftp://ftp.gnustep.org/pub/gnustep/%SUBDIR%/
DISTNAME=	ProjectCenter-${PORTVERSION}
MASTER_SITE_SUBDIR=	dev-apps

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	A development environment for GNUstep

PREFIX=		${LOCALBASE}/GNUstep
NO_MTREE=	yes
WRKSRC=		${WRKDIR}/ProjectCenter
USE_GMAKE=	yes
MAKEFILE=	GNUmakefile
MAKE_ENV+=	ADDITIONAL_INCLUDE_DIRS="-I${WRKSRC}"
MAKE_ENV+=	ADDITIONAL_LIB_DIRS="-L${WRKSRC}/PCLib/shared_obj/${GNU_ARCH}/${OPSYS:L}/gnu-gnu-gnu"

FIXME=		GNUmakefile.bundles GNUmakefile.preamble \
		PCLib/GNUmakefile.preamble

.include <bsd.port.pre.mk>

USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
.include "${PORTSDIR}/devel/gnustep/bsd.gnustep.mk"

# Quick workaround until I find out how to set the real path in the code
post-patch:
.for file in PCLib/PCBundleLoader.m PCAppController.m
	@${MV} ${WRKSRC}/${file} ${WRKSRC}/${file}.sed
	${SED} -e "s=@\"/usr/GNUstep=@\"${PREFIX}=g" \
		${WRKSRC}/${file}.sed > ${WRKSRC}/${file}
.endfor
.for file in ${FIXME}
	@${MV} ${WRKSRC}/${file} ${WRKSRC}/${file}.sed
	${SED} -e "s=-Werror==g" \
		${WRKSRC}/${file}.sed > ${WRKSRC}/${file}
.endfor

.include <bsd.port.post.mk>
