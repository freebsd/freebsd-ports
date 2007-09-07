# New ports collection makefile for:    zeroinstall-injector
# Date created:         2007-06-24
# Whom:                 Dylan Cochran <a134qaed@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	zeroinstall-injector
PORTVERSION=	0.29
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=zero-install
EXTRACT_SUFX=	.tar.gz.gpg

MAINTAINER=	a134qaed@gmail.com
COMMENT=	0install injector

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-2.0/gtk/_gtk.so:${PORTSDIR}/x11-toolkits/py-gtk2
RUN_DEPENDS+=	gpg:${PORTSDIR}/security/gnupg
EXTRACT_DEPENDS=gpg:${PORTSDIR}/security/gnupg

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

MAN1=		0launch.1 0alias.1 0store.1

do-extract:
	@${RM} -rf ${DISTDIR}/${DISTNAME}.tar.gz
	@gpg --recv-key --keyserver www.keyserver.net 59A53CC1
	@gpg ${DISTDIR}/${DISTFILES}
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	cd ${WRKDIR} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
		${DISTDIR}/${DISTNAME}.tar.gz ${EXTRACT_AFTER_ARGS}

.include <bsd.port.mk>
