# New ports collection makefile for:	cvsweb
# Version required:	1.0
# Date created:		27 Jun 1999
# Whom:			SADA Kenji <sada@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	cvsweb-1.0
CATEGORIES=	devel www
MASTER_SITES=	http://people.FreeBSD.org/~fenner/cvsweb/

MAINTAINER=	knu@idaemons.org

NO_BUILD=	yes

# Specify where your repository belongs.
# (You can reconfigure it after installation anyway)
.if defined(PACKAGE_BUILDING) || !defined(CVSROOT) || empty(CVSROOT)
CVSROOT=	/home/ncvs
.endif

# Specify the title of your cvsweb site.
TITLE?=		My CVS Repository

# Specify the cgi-bin directory in relative paths to ${PREFIX}.
CGIDIR?=	share/apache/cgi-bin

PLIST_SUB=	CGIDIR="${CGIDIR}"

do-configure:
	${SED}	-e "s;!!CVSROOT!!;${CVSROOT};g" \
		-e "s;!!TITLE!!;${TITLE};g" \
		${WRKSRC}/cvsweb > ${WRKSRC}/cvsweb.cgi

do-install:
	${MKDIR} ${PREFIX}/${CGIDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/cvsweb.cgi ${PREFIX}/${CGIDIR}/
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/cvsweb
	cd ${WRKSRC} && ${INSTALL_DATA} README ${PREFIX}/share/doc/cvsweb/
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
