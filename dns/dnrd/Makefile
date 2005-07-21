# New ports collection makefile for:   dnrd
# Date created:        06 January 2001
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=		dnrd
PORTVERSION=		2.19.1
CATEGORIES=		dns
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	dnrd

MAINTAINER=		ncopa@users.sourceforge.net
COMMENT=		A proxy DNS daemon

USE_GMAKE=		yes
USE_REINPLACE=		yes
USE_RC_SUBR=		yes
GNU_CONFIGURE=		yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=		PTHREAD_CFLAGS=${PTHREAD_CFLAGS} PTHREAD_LIBS=${PTHREAD_LIBS}

.if defined(WITH_TCP)
CONFIGURE_ARGS+=	--enable-tcp
.endif

.if defined(WITHOUT_MASTER)
CONFIGURE_ARGS+=	--disable-master
.endif

MAN8=			dnrd.8
DOCS=			AUTHORS ChangeLog INSTALL README \
			doc/README-cache doc/README-master  doc/TODO
EXAMPLES=		doc/master.sample

post-patch:
	@${SED} -e 's|%%RC_SUBR%%|${RC_SUBR}|g' -e 's|%%PREFIX%%|${PREFIX}|' \
		${FILESDIR}/dnrd.sh > ${WRKDIR}/dnrd.sh

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/dnrd.sh ${PREFIX}/etc/rc.d/dnrd.sh
	${INSTALL_PROGRAM} ${WRKSRC}/src/dnrd ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/doc/dnrd.8 ${MAN8PREFIX}/man/man8
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${EXAMPLES} ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
