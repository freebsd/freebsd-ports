# New ports collection makefile for:	cvsweb
# Date created:		27 Jun 1999
# Whom:			SADA Kenji <sada@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cvsweb
PORTVERSION=	${REV_ZELLER}.${REV_KNU}
CATEGORIES=	devel www
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://www.iDaemons.org/distfiles/
MASTER_SITE_SUBDIR=	knu

MAINTAINER=	knu@FreeBSD.org

NO_BUILD=	yes

USE_PERL5=	yes

# This version of cvsweb is Zeller's version + knu's enhancements.
REV_ZELLER=	1.106
REV_KNU=	1.70

# Specify where your repository belongs.
# (You can reconfigure it after installation anyway)
.if defined(PACKAGE_BUILDING) || !defined(CVSROOT) || empty(CVSROOT)
CVSROOT=	/home/cvs
.endif

# Specify the title of your cvsweb site.
TITLE?=		My CVS Repository

# Specify these directories in relative paths to ${PREFIX}.
.if !exists(${PREFIX}/www) && exists(${PREFIX}/share/apache)
CGIDIR?=	share/apache/cgi-bin
ICONSDIR?=	share/apache/icons
.else
CGIDIR?=	www/cgi-bin
ICONSDIR?=	www/icons
.endif

CONFFILES=	cvsweb.conf \
		cvsweb.conf-freebsd \
		cvsweb.conf-openbsd \
		cvsweb.conf-netbsd \
		cvsweb.conf-ruby

PLIST_SUB=	CGIDIR="${CGIDIR}" ICONSDIR="${ICONSDIR}"

WRKSRC=		${WRKDIR}/${PORTNAME}

post-patch:
	${PERL} -i -pe "\
		s;!!PERL!!;${PERL};g; \
		s;!!PREFIX!!;${PREFIX};g;" \
		${WRKSRC}/cvsweb.cgi
	${PERL} -i -pe "\
		s;!!PREFIX!!;${PREFIX};g; \
		s;!!CVSROOT!!;${CVSROOT};g; \
		s;!!TITLE!!;${TITLE};g;" \
		${WRKSRC}/cvsweb.conf

do-install:
	${MKDIR} ${PREFIX}/${CGIDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/cvsweb.cgi ${PREFIX}/${CGIDIR}/
	${MKDIR} ${PREFIX}/etc/cvsweb
.for f in ${CONFFILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/etc/cvsweb/${f}.dist
.endfor
	${MKDIR} ${PREFIX}/${ICONSDIR}/cvsweb
	cd ${WRKSRC}/icons && ${INSTALL_DATA} * ${PREFIX}/${ICONSDIR}/cvsweb/
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/cvsweb
	cd ${WRKSRC} && ${INSTALL_DATA} ChangeLog INSTALL README README.knu TODO TODO.knu ${PREFIX}/share/doc/cvsweb/
.endif

post-install:
.if defined(PACKAGE_BUILDING)
	${ECHO} "@unexec rmdir -p %D/${CGIDIR} %D/${ICONSDIR} 2>/dev/null || true" >> ${TMPPLIST}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
