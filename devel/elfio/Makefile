# ex:ts=8
# New ports collection makefile for:	elfio
# Date created:			Jul 26, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	elfio
PORTVERSION=	1.0.3
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME:U}-${PORTVERSION}

MAINTAINER=	stas@FreeBSD.org
COMMENT=	C++ library for reading and generating files in the ELF binary format

GNU_CONFIGURE=	yes
USE_GNOME=	gnometarget

OPTIONS=	EXAMPLES "Install sample programms" on

PORTDOCS=	*

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_EXAMPLES)
PLIST_SUB+=	EXAMPLES=""
.else
PLIST_SUB+=	EXAMPLES="@comment "
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in AUTHORS ChangeLog README
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.for f in elf11g.zip tutorial.docbook tutorial.pdf
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${DOCSDIR}
.endfor
.endif
.if !defined(WITHOUT_EXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@${FIND} ${WRKSRC}/Examples/ -name "*.cpp" -exec ${INSTALL_DATA} {} \
		${EXAMPLESDIR}/ \;
.endif

.include <bsd.port.post.mk>
