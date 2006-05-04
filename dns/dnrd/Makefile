# New ports collection makefile for:   dnrd
# Date created:        06 January 2001
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=		dnrd
PORTVERSION=		2.20.1
CATEGORIES=		dns
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	dnrd

MAINTAINER=		ncopa@users.sourceforge.net
COMMENT=		A proxy DNS daemon

USE_GMAKE=		yes
USE_RC_SUBR=		${PORTNAME}.sh
GNU_CONFIGURE=		yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=		PTHREAD_CFLAGS=${PTHREAD_CFLAGS} PTHREAD_LIBS=${PTHREAD_LIBS}
CONFIGURE_ARGS+=	--disable-dependency-tracking

MAN8=		dnrd.8
DOCS=		AUTHORS ChangeLog INSTALL README \
		doc/README-cache doc/README-master  doc/TODO
EXAMPLES=	doc/master.sample

PORTDOCS=	*
PLIST_FILES=	sbin/dnrd %%EXAMPLESDIR%%/master.sample
PLIST_DIRS=	%%EXAMPLESDIR%% etc/dnrd

OPTIONS=	TCP "Enable TCP support" off \
		MASTER "Enable master file support" on

.include <bsd.port.pre.mk>

.if defined(WITH_TCP)
CONFIGURE_ARGS+=	--enable-tcp
.endif

.if defined(WITHOUT_MASTER)
CONFIGURE_ARGS+=	--disable-master
.endif

pre-install:
	@${ECHO} "==>  Creating custom user to run dnrd..."
	@${SETENV} PKG_PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	@${ECHO} "==>  Creating dnrd directory"
	@${SETENV} PKG_PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/dnrd ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/doc/dnrd.8 ${MAN8PREFIX}/man/man8
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${EXAMPLES} ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
