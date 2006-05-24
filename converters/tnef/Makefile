# New ports collection makefile for:	tnef
# Date created:		19 September 2000
# Whom:			Cyrus Rahman <cr@jcmax.com>
#
# $FreeBSD$
#

PORTNAME=	tnef
PORTVERSION=	1.4.1
CATEGORIES=	converters mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	cr@jcmax.com
COMMENT=	Unpack data in MS Outlook TNEF format

GNU_CONFIGURE=		yes
USE_GETOPT_LONG=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=		tnef.1
PORTDOCS=	AUTHORS NEWS README THANKS TODO
PLIST_FILES=	bin/tnef

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

# This target is intended to be run by the port maintainer.
x-test: build
.for dir in cmdline files
	@cd ${WRKSRC}/tests/${dir} && ${MAKE} check-TESTS
.endfor

.include <bsd.port.mk>
