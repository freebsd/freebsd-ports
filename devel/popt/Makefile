# New ports collection makefile for:	popt
# Date Created:				29 Dec 1999
# Whom:					Yuan-Chen Cheng <ycheng@sinica.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	popt
PORTVERSION=	1.4
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.redhat.com/redhat/current/SRPMS/SRPMS/ \
		ftp://ftp.freesoftware.com/pub/linux/redhat/current/SRPMS/SRPMS/
EXTRACT_SUFX=	-1.src.rpm

MAINTAINER=	ycheng@sinica.edu.tw

BUILD_DEPENDS=	${LOCALBASE}/bin/rpm2cpio:${PORTSDIR}/misc/rpm
LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAN3=		popt.3
MANCOMPRESSED=	no

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	@${LOCALBASE}/bin/rpm2cpio ${_DISTDIR}${DISTFILES} | (cd ${WRKDIR}; cpio -i)
	@tar -xzf ${WRKDIR}/${DISTNAME}.tar.gz -C ${WRKDIR}

.include <bsd.port.mk>
