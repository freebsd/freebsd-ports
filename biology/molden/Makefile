# New ports collection makefile for:	molden
# Date created:		1998-11-14
# Whom:			rmiya
#
# $FreeBSD$
#

PORTNAME=	molden
PORTVERSION=	3.6
PORTREVISION=	1
CATEGORIES=	biology
MASTER_SITES=	ftp://ftp.cmbi.kun.nl/pub/molgraph/molden/
DISTNAME=	${PORTNAME}${PORTVERSION}
EXTRACT_SUFX=	.tar.Z
EXTRACT_ONLY=	${PORTNAME}${PORTVERSION}.tar.Z

PATCH_SITES=	ftp://ftp.cmbi.kun.nl/pub/molgraph/molden/bin/
PATCHFILES=	${PORTNAME}${PORTVERSION}-freebsd

MAINTAINER=	rmiya@cc.hirosaki-u.ac.jp

RESTRICTED=	"free for academic, non profit usage;"
NO_CDROM=	"Do not re-distribute source and executable."
NO_PACKAGE=	"Though the source codes is accessible, the author is hoping for distribution in an original binary form."
MAKEFILE=	${WRKSRC}/makefile

.include <bsd.port.pre.mk>

post-configure:
	@${ECHO_MSG} "********************"
	@${ECHO_MSG} "**  If you want to use a larger MOLDEN,"
	@${ECHO_MSG} "**  edit change_parameter, change_parameter.sh"
	@${ECHO_MSG} "**  or utils/*, and run them before building it."
	@${ECHO_MSG} "********************"

pre-build:
.if defined(ORIGINALBINARY)
	@${ECHO_MSG} "********************"
	@${ECHO_MSG} "**  using original binary"
	@${ECHO_MSG} "********************"
.elif defined(MYBINARY)
	@${ECHO_MSG} "********************"
	@${ECHO_MSG} "**  re-build your own MOLDEN"
	@${ECHO_MSG} "********************"
.else
	@${ECHO_MSG} "********************"
	@${ECHO_MSG} "**  set ORIGINALBINARY=yes or MYBINARY=yes"
	@${ECHO_MSG} "********************"
	@exit 1
.endif

do-build:
.if defined(ORIGINALBINARY)
	${CP}  ${DISTDIR}/${PORTNAME}${PORTVERSION}-freebsd ${WRKSRC}/molden
.elif defined(MYBINARY)
	(cd ${WRKSRC} && ${MAKE})
.else
	@${ECHO_MSG} "********************"
	@${ECHO_MSG} "**  set ORIGINALBINARY=yes or MYBINARY=yes"
	@${ECHO_MSG} "********************"
.endif

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
