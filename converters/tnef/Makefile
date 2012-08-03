# New ports collection makefile for:	tnef
# Date created:		19 September 2000
# Whom:			Cyrus Rahman <cr@jcmax.com>
#
# $FreeBSD$
#

PORTNAME=	tnef
PORTVERSION=	1.4.9
CATEGORIES=	converters mail
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Unpack data in MS Outlook TNEF format

OPTIONS_DEFINE=	DOCS

GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

MAN1=		tnef.1
PORTDOCS=	AUTHORS NEWS README THANKS TODO
PLIST_FILES=	bin/tnef

.include <bsd.port.pre.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

# This target is intended to be run by the port maintainer.
x-test: build
.for dir in cmdline files
	@cd ${WRKSRC}/tests/${dir} && ${MAKE} check-TESTS
.endfor

.include <bsd.port.post.mk>
