# New ports collection makefile for:   xtr
# Date created:			5 November 2002
# Whom:				TANAKA Hiroyuki <kattyo@abk.nu>
#
# $FreeBSD$
#

PORTNAME=	xtr
PORTVERSION=	1.50e.0.2
CATEGORIES=	japanese textproc
MASTER_SITES=	ftp://ftp.abk.nu/pub/redist/xtr/
DISTNAME=	${PORTNAME}1.50e-0.2
EXTRACT_SUFX=	.tgz

MAINTAINER=	kattyo-ports@abk.nu
COMMENT=	A powerful Japanese text formatting processor

MAN1=		xtr.1
MANCOMPRESSED=	no

HAS_CONFIGURE=	yes
GNU_CONFIGURE=	yes

NO_CDROM=	"Need to obtain permission for commercial redistribution."

.include <bsd.port.pre.mk>

post-extract:
	@${ECHO_MSG} "===>  Converting Kanji code for ${DISTNAME}"
	@(cd ${WRKSRC} && $(SH) EUCsetup )

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/xtr ${PREFIX}/bin/xtr
	${INSTALL_MAN} ${WRKSRC}/man/${PORTNAME}.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in README doc/xtr.doc
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif
	@${MKDIR} ${PREFIX}/share/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/sample/*.xtr ${PREFIX}/share/${PORTNAME}

.include <bsd.port.post.mk>
