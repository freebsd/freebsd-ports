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

USE_BZIP2=	yes
USE_REINPLACE=	yes
USE_LIBTOOL=	yes
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

# it would really be best if the patch-libtool target was run just
# after pre-configure instead of just before.  To get around this, we
# touch LIBTOOLFILES so patch-libtool doesn't barf, then run
# patch-libtool again after running aclocal and autoheader.  Hopefully
# future changes to bsd.port.mk won't cause this to break.
post-patch:
	@cd ${WRKSRC} && ${TOUCH} ${LIBTOOLFILES}

pre-configure:
	@cd ${WRKSRC} && ${ACLOCAL} && ${AUTOHEADER}
#	@${MAKE} patch-libtool

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
