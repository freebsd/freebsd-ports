# Created by: michaels@sdf.lonestar.org
# $FreeBSD$

PORTNAME=	emu10kx
PORTVERSION=	20051021
CATEGORIES=	audio kld
MASTER_SITES=	http://chibis.persons.gfk.ru/audigy/emu10kx/
DISTNAME=	${PORTNAME}-2005-10-21

MAINTAINER=	michaels@sdf.lonestar.org
COMMENT=	SBLive!, Audigy, and Audigy2 driver for FreeBSD

USE_BZIP2=	yes
NO_STAGE=	yes

NO_PACKAGE=	should be recompiled for a particular FreeBSD kernel
SSP_UNSAFE=	kernel module does not support ssp

MAN8=	emuctrl.8
PLIST_FILES=	sbin/emuctrl etc/rc.d/emuctrl.sh
WRKSRC=	${WRKDIR}/${DISTNAME}

.include <bsd.port.pre.mk>

do-install:
	@${SETENV} ${MAKE_ENV} ${MAKE} -C ${WRKSRC} -DMODULES_WITH_WORLD install

post-install:
.if !defined(BATCH) && !defined(PACKAGE_BUILDING)
	@${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
