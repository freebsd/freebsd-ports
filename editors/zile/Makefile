# New ports collection Makefile for:	zile
# Date created:		28 September 2000
# Whom:			jasone
#
# $FreeBSD$
#

PORTNAME=	zile
PORTVERSION=	2.0.6
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small emacs-like text editor

USE_GCC=	3.4
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_AUTOMAKE_VER=	19
USE_AUTOCONF_VER=	259
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=		zile.1
INFO=		zile
PLIST_FILES=	bin/zile %%DATADIR%%/AUTODOC %%DATADIR%%/FAQ %%DATADIR%%/HELP \
		%%DATADIR%%/TUTORIAL %%DATADIR%%/zilerc.sample
PLIST_DIRS=	%%DATADIR%%

post-extract:
	@${RM} -f ${WRKSRC}/doc/zile.info

post-patch:
	@${REINPLACE_CMD} -e '/^BFD_CC_FOR_BUILD/d' ${WRKSRC}/configure.ac
	@${GREP} -lR "Makefile.am" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|_FOR_BUILD||g'

pre-configure:
	@cd ${CONFIGURE_WRKSRC} && ${ACLOCAL}

.include <bsd.port.mk>
