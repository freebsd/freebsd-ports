# New ports collection makefile for:	cvsweb
# Date created:		27 Jun 1999
# Whom:			SADA Kenji <sada@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cvsweb
PORTVERSION=	3.0.5
PORTREVISION=	1
CATEGORIES=	devel www
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://people.FreeBSD.org/~scop/cvsweb/
MASTER_SITE_SUBDIR=	scop

# For issues that are not specific to this port/package, please consult
# the <freebsd-cvsweb@FreeBSD.org> mailing list.
MAINTAINER=	noackjr@alumni.rice.edu
COMMENT=	WWW CGI script to browse CVS repository trees version 3

RUN_DEPENDS=	${SITE_PERL}/IPC/Run.pm:${PORTSDIR}/devel/p5-IPC-Run \
		${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI

# The following extra dependencies are optional, but CVSweb works the
# best with them.
RUN_DEPENDS+=	${SITE_PERL}/MIME/Types.pm:${PORTSDIR}/mail/p5-MIME-Types \
		${SITE_PERL}/${PERL_ARCH}/String/Ediff.pm:${PORTSDIR}/devel/p5-String-Ediff \
		cvsgraph:${PORTSDIR}/devel/cvsgraph

# Use PAPERSIZE to avoid a stale dependency on Enscript.
PAPERSIZE?=	letter
RUN_DEPENDS+=	enscript:${PORTSDIR}/print/enscript-${PAPERSIZE}

LATEST_LINK=	cvsweb3
CONFLICTS=	cvsweb-2.*

NO_BUILD=	yes
USE_PERL5=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		Port requires perl 5.6.1 or later. Install lang/perl5 then try again
.endif

.if ${PERL_LEVEL} < 500800
RUN_DEPENDS+=	${SITE_PERL}/File/Temp.pm:${PORTSDIR}/devel/p5-File-Temp
.endif

# Specify where your repository belongs.
# (You can reconfigure it after installation anyway)
.if defined(PACKAGE_BUILDING) || !defined(CVSROOT) || empty(CVSROOT)
CVSROOT=	/home/cvs
.endif

# Specify the title of your cvsweb site.
TITLE?=		My CVS Repository

# Specify these directories in relative paths to ${PREFIX}.
.if exists(${PREFIX}/www/cgi-bin)
CGIDIR?=	www/cgi-bin
ICONSDIR?=	www/icons
CSSDIR?=	www/data/css
.elif exists(${PREFIX}/apache/cgi-bin)
CGIDIR?=	apache/cgi-bin
ICONSDIR?=	apache/icons
CSSDIR?=	apache/data/css
.else
CGIDIR?=	share/apache/cgi-bin
ICONSDIR?=	share/apache/icons
CSSDIR?=	share/apache/data/css
.endif

CONFFILES=	cvsweb.conf \
		cvsweb.conf-freebsd \
		cvsweb.conf-openbsd \
		cvsweb.conf-netbsd \
		cvsweb.conf-ruby

PLIST_SUB=	CGIDIR="${CGIDIR}" ICONSDIR="${ICONSDIR}" CSSDIR="${CSSDIR}"

SUB_FILES=	pkg-message
SUB_LIST=	PREFIX="${PREFIX}" DOCSDIR="${DOCSDIR}"

post-patch:
	${PERL} -i -pe "\
		s'!!PERL!!'${PERL}'g; \
		s'!!PREFIX!!'${PREFIX}'g;" \
		${WRKSRC}/cvsweb.cgi
	${PERL} -i -pe "\
		s'!!PREFIX!!'${PREFIX}'g; \
		s'!!CVSROOT!!'${CVSROOT}'g; \
		s'!!TITLE!!'${TITLE}'g;" \
		${WRKSRC}/cvsweb.conf

do-install:
	${MKDIR} ${PREFIX}/${CGIDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/cvsweb.cgi ${PREFIX}/${CGIDIR}/
	${MKDIR} ${PREFIX}/etc/cvsweb
.for f in ${CONFFILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/etc/cvsweb/${f}.dist
.endfor
	${MKDIR} ${PREFIX}/${ICONSDIR}/cvsweb
	${INSTALL_DATA} ${WRKSRC}/icons/* ${PREFIX}/${ICONSDIR}/cvsweb/
	${MKDIR} ${PREFIX}/${CSSDIR}/cvsweb
	${INSTALL_DATA} ${WRKSRC}/css/*.css ${PREFIX}/${CSSDIR}/cvsweb/
	${MKDIR} ${PREFIX}/share/enscript/hl
	${INSTALL_DATA} ${WRKSRC}/enscript/*.st ${PREFIX}/share/enscript/hl/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ChangeLog INSTALL NEWS README TODO
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/* ${EXAMPLESDIR}/
.endif

post-install:
.if defined(PACKAGE_BUILDING)
	${ECHO_CMD} "@unexec rmdir -p %D/${CGIDIR} %D/${ICONSDIR} %D/${CSSDIR} 2>/dev/null || true" >> ${TMPPLIST}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
