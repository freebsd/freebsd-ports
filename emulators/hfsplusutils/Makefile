# New ports collection makefile for:	hfsplusutils
# Date created:		2003-11-11
# Whom:			Josh Elsasser <jre@vineyard.net>
#
# $FreeBSD$
#

PORTNAME=	hfsplusutils
PORTVERSION=	1.0.4
CATEGORIES=	emulators
MASTER_SITES=	ftp://ftp.penguinppc.org/users/hasi/
DISTNAME=	hfsplus_${PORTVERSION}.src

MAINTAINER=	jre@vineyard.net
COMMENT=	Utilities for accessing HFS+ filesystems

BROKEN=		"Does not compile"
DEPRECATED=	${BROKEN}
EXPIRATION_DATE=2004-06-18

USE_BZIP2=	yes
USE_REINPLACE=	yes
USE_LIBTOOL_VER=	13
INSTALLS_SHLIB=	yes
USE_AUTOMAKE_VER=	15
AUTOMAKE_ARGS=		--add-missing
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

WRKSRC=		${WRKDIR}/hfsplus-${PORTVERSION}

MAN1=		hfsp.1
DOCS=		AUTHORS ChangeLog NEWS README index.html doc/*.html

pre-patch:
	@${REINPLACE_CMD} -e 's/^CFLAGS.*/CFLAGS=@CFLAGS@/' \
		${WRKSRC}/src/Makefile.am ${WRKSRC}/libhfsp/src/Makefile.am
	@${REINPLACE_CMD} -e 's,doc/,,' ${WRKSRC}/index.html

pre-configure:
	@cd ${WRKSRC} && ${ACLOCAL} && ${AUTOHEADER}

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/man/hfsp.man ${MAN1PREFIX}/man/man1/hfsp.1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=	"Does not build on FreeBSD 4.x or earlier"
.endif

.include <bsd.port.post.mk>
