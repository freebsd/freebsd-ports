# New ports collection makefile for:	pmake
# Date created:		12 November 1998
# Whom:			steve
#
# $FreeBSD$
#

PORTNAME=	pmake
PORTVERSION=	2.1.36
CATEGORIES=	devel parallel
MASTER_SITES=	ftp://ftp.icsi.berkeley.edu/pub/ai/stolcke/software/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	steve
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	steve@freebsd.org
COMMENT=	The parallel make(1) program from the Sprite project

RESTRICTED=	"Non-commercial use only"

WRKSRC=		${WRKDIR}/pmake
MAKEFILE=	makefile
ALL_TARGET=	pmake
PMAKE_ENV=	${MAKE_ENV} MAKE=${PREFIX}/bin/pmake
USE_REINPLACE=	yes
MAN1=		pmake.1

post-patch:
	@${REINPLACE_CMD} '/memmove/d' ${WRKSRC}/lib/include/sprite.h

#
# Define this if you want to build and install with the 'customs'
# server support and the pmake to match.  Note, you'll still get
# the plain pmake in ${PREFIX}/bin/pmake.nocustoms.
#
#WANT_CUSTOMS=	yes

do-install::
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} install)

.if defined(WANT_CUSTOMS)
PLIST=		${PKGDIR}/pkg-plist.customs
MAN1+=		export.1 reginfo.1 rexport.1
MAN8=		cctrl.8 customs.8 importquota.8 logd.8

do-install::
	@(cd ${WRKSRC}; ${SETENV} ${PMAKE_ENV} ${PREFIX}/bin/pmake new; \
	  ${SETENV} ${PMAKE_ENV} ${PREFIX}/bin/pmake install)
	@${ECHO} "Adding customs service to /etc/services..."
	@${ECHO_CMD} -e 'customs\t\t8231/tcp\t# pmake customs server'>>/etc/services
	@${ECHO_CMD} -e 'customs\t\t8231/udp\t# pmake customs server'>>/etc/services
.else
do-install::
	@(cd ${WRKSRC}/doc; ${SETENV} ${PMAKE_ENV} ${MAKE})
	${INSTALL_MAN} ${WRKSRC}/doc/pmake.1 ${PREFIX}/man/man1
.endif

.include <bsd.port.mk>
