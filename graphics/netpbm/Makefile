# New ports collection makefile for:	netpbm
# Date created:		?
# Whom:			jmz (original)
#
# $FreeBSD$
#

PORTNAME=	netpbm
PORTVERSION=	9.23
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png

USE_GMAKE=	yes
MAKE_ENV=	LN="${LN}" RANLIB="${RANLIB}"
MAKEFILE=	GNUmakefile
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

.include "${FILESDIR}/manpages"

post-patch:
	@${PERL} -pi -e 's|%%X11BASE%%|${X11BASE}|g' ${WRKSRC}/pm_config.h
	@${PERL} -pi -e 's|<shhopt.h>|<pm_shhopt.h>|g' ${WRKSRC}/pbm/pm.h
	@${CP} ${FILESDIR}/Makefile.config.FreeBSD ${WRKSRC}/Makefile.config
	@${LN} -sf ${WRKSRC}/shhopt/shhopt.h ${WRKSRC}/shhopt/pm_shhopt.h

.include <bsd.port.post.mk>
