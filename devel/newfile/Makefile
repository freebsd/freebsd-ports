# Created by: Miguel Mendez <flynn@energyhq.homeip.net>
# $FreeBSD$

PORTNAME=	newfile
PORTVERSION=	1.0.14
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tool for creating starter files in various languages

USE_RUBY=	yes
GNU_CONFIGURE=	yes

MAN1=		newfile.1
DOCS=		doc/newfile.html

.include <bsd.port.options.mk>

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/newfile.1 ${MAN1PREFIX}/man/man1
.if defined (${PORT_OPTIONS:MDOCS})
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
