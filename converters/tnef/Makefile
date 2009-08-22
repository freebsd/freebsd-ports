# New ports collection makefile for:	tnef
# Date created:		19 September 2000
# Whom:			Cyrus Rahman <cr@jcmax.com>
#
# $FreeBSD$
#

PORTNAME=	tnef
PORTVERSION=	1.4.5
CATEGORIES=	converters mail
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/v${PORTVERSION}

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Unpack data in MS Outlook TNEF format

GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

MAN1=		tnef.1
PORTDOCS=	AUTHORS NEWS README THANKS TODO
PLIST_FILES=	bin/tnef

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

# This target is intended to be run by the port maintainer.
x-test: build
.for dir in cmdline files
	@cd ${WRKSRC}/tests/${dir} && ${MAKE} check-TESTS
.endfor

.include <bsd.port.mk>
