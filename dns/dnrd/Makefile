# New ports collection makefile for:   dnrd
# Date created:        06 January 2001
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=		dnrd
PORTVERSION=		2.14
CATEGORIES=		dns
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	dnrd

MAINTAINER=		ports@FreeBSD.org
COMMENT=		A proxy DNS daemon

USE_GMAKE=		yes
USE_REINPLACE=		yes
USE_RC_SUBR=		yes
GNU_CONFIGURE=		yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=		PTHREAD_CFLAGS=${PTHREAD_CFLAGS} PTHREAD_LIBS=${PTHREAD_LIBS}

MAN8=			dnrd.8

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/dnrd|${PREFIX}/etc/dnrd|g' ${WRKSRC}/doc/dnrd.8 \
		${WRKSRC}/doc/master.sample ${WRKSRC}/doc/README-master ${WRKSRC}/src/common.h \
		${WRKSRC}/src/master.c ${WRKSRC}/src/main.c
	@${SED} -e 's|%%RC_SUBR%%|${RC_SUBR}|g' -e 's|%%PREFIX%%|${PREFIX}|' \
		${FILESDIR}/dnrd.sh > ${WRKDIR}/dnrd.sh

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/dnrd.sh ${PREFIX}/etc/rc.d/dnrd.sh

.include <bsd.port.mk>
