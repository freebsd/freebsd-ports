# New ports collection makefile for:	molden
# Date created:		1998-11-14
# Whom:			rmiya
#
# $FreeBSD$
#

PORTNAME=	molden
PORTVERSION=	3.7
CATEGORIES=	biology
MASTER_SITES=	ftp://ftp.cmbi.kun.nl/pub/molgraph/molden/
DISTNAME=	${PORTNAME}${PORTVERSION}
EXTRACT_SUFX=	.tar.Z
EXTRACT_ONLY=	${PORTNAME}${PORTVERSION}.tar.Z

MAINTAINER=	rmiya@cc.hirosaki-u.ac.jp

USE_XLIB=	yes

RESTRICTED=	"free for academic, non profit usage;"
NO_CDROM=	"Do not re-distribute source and executable."
NO_PACKAGE=	"Though the source codes are accessible, the author is hoping for distribution in an original form."
MAKEFILE=	${WRKSRC}/makefile

.include <bsd.port.pre.mk>

post-configure:
	@${ECHO_MSG} "********************"
	@${ECHO_MSG} "**  If you want to use a larger MOLDEN,"
	@${ECHO_MSG} "**  edit change_parameter.sh and run it,"
	@${ECHO_MSG} "**  before \'make build\'."
	@${ECHO_MSG} "********************"

do-build:
	(cd ${WRKSRC} && ${MAKE})

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/molden ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/molden
	${MKDIR} ${PREFIX}/share/molden/test
	${MKDIR} ${PREFIX}/share/molden/utils
	${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/doc/molden
	${INSTALL_DATA} ${WRKSRC}/test/* ${PREFIX}/share/molden/test
	${INSTALL_DATA} ${WRKSRC}/utils/* ${PREFIX}/share/molden/utils
.endif

.include <bsd.port.post.mk>
