# New ports collection makefile for:	cvsweb
# Version required:	1.80
# Date created:		27 Jun 1999
# Whom:			SADA Kenji <sada@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	cvsweb-1.80
CATEGORIES=	devel www
MASTER_SITES=	http://stud.fh-heilbronn.de/~zeller/download/

MAINTAINER=	knu@idaemons.org

NO_BUILD=	yes

# Specify where your repository belongs.
# (You can reconfigure it after installation anyway)
.if defined(PACKAGE_BUILDING) || !defined(CVSROOT) || empty(CVSROOT)
CVSROOT=	/home/ncvs
.endif

# Specify the title of your cvsweb site.
TITLE?=		My CVS Repository

# Specify these directories in relative paths to ${PREFIX}.
CGIDIR?=	share/apache/cgi-bin
ICONSDIR?=	share/apache/icons

PLIST_SUB=	CGIDIR="${CGIDIR}" ICONSDIR="${ICONSDIR}"

WRKSRC=		${WRKDIR}/cvsweb

do-configure:
	cd ${WRKSRC} && ${PERL} -i -pe "\
		s;!!PREFIX!!;${PREFIX};g; \
		s;!!CVSROOT!!;${CVSROOT};g; \
		s;!!TITLE!!;${TITLE};g; \
		" cvsweb.cgi cvsweb.conf

do-install:
	${MKDIR} ${PREFIX}/${CGIDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/cvsweb.cgi ${PREFIX}/${CGIDIR}/
	${INSTALL_DATA} ${WRKSRC}/cvsweb.conf ${PREFIX}/etc/cvsweb.conf.sample
	${MKDIR} ${PREFIX}/${ICONSDIR}/cvsweb
	cd ${WRKSRC}/icons && ${INSTALL_DATA} * ${PREFIX}/${ICONSDIR}/cvsweb/
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/cvsweb
	cd ${WRKSRC} && ${INSTALL_DATA} INSTALL README TODO ${PREFIX}/share/doc/cvsweb/
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
