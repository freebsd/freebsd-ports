# Created by: SADA Kenji <sada@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cvsweb
PORTVERSION=	3.0.6
PORTREVISION=	4
CATEGORIES=	devel www
MASTER_SITES=	LOCAL/scop http://people.FreeBSD.org/~scop/cvsweb/
PKGNAMESUFFIX=	3

# For issues that are not specific to this port/package, please consult
# the <freebsd-cvsweb@FreeBSD.org> mailing list.
MAINTAINER=	noackjr@alumni.rice.edu
COMMENT=	WWW CGI script to browse CVS repository trees version 3

RUN_DEPENDS=	p5-IPC-Run>=0:devel/p5-IPC-Run \
		p5-URI>=0:net/p5-URI

# The following extra dependencies are optional, but CVSweb works the
# best with them.
RUN_DEPENDS+=	p5-MIME-Types>=0:mail/p5-MIME-Types \
		p5-String-Ediff>=0:devel/p5-String-Ediff \
		cvsgraph:devel/cvsgraph

# Use PAPERSIZE to avoid a stale dependency on Enscript.
PAPERSIZE?=	letter
RUN_DEPENDS+=	enscript:print/enscript-${PAPERSIZE}

CONFLICTS=	cvsweb-2.*

USES=		perl5 shebangfix
SHEBANG_FILES=	cvsweb.cgi
NO_BUILD=	yes

.include <bsd.port.pre.mk>

# Specify where your repository belongs.
# (You can reconfigure it after installation anyway)
.if defined(PACKAGE_BUILDING) || !defined(CVSROOT) || empty(CVSROOT)
CVSROOT=	/home/cvs
.endif

# Specify the title of your cvsweb site.
TITLE?=		My CVS Repository

# Specify these directories in relative paths to ${PREFIX}.
.if exists(${PREFIX}/www/cgi-bin)
DIRPREFIX=	www
.elif exists(${PREFIX}/www/apache24/cgi-bin)
DIRPREFIX=      www/apache24
.elif exists(${PREFIX}/www/apache22/cgi-bin)
DIRPREFIX=	www/apache22
.elif exists(${PREFIX}/apache/cgi-bin)
DIRPREFIX=	apache
.else
DIRPREFIX=	share/apache
.endif
CGIDIR?=        ${DIRPREFIX}/cgi-bin
ICONSDIR?=      ${DIRPREFIX}/icons
CSSDIR?=        ${DIRPREFIX}/data/css

CONFFILES=	cvsweb.conf \
		cvsweb.conf-freebsd \
		cvsweb.conf-openbsd \
		cvsweb.conf-netbsd \
		cvsweb.conf-ruby

PLIST_SUB=	CGIDIR="${CGIDIR}" ICONSDIR="${ICONSDIR}" CSSDIR="${CSSDIR}" \
		DIRPREFIX="${DIRPREFIX}"

SUB_FILES=	pkg-message
SUB_LIST=	PREFIX="${PREFIX}" DOCSDIR="${DOCSDIR}"

post-patch:
	@${SED} -i '' -e 's,/usr/local/etc/,${PREFIX}/etc/,' \
		-e 's,\(qw(hi.*)\),(\1),' ${WRKSRC}/cvsweb.cgi
	@${REINPLACE_CMD} -i '' -e 's,!!PREFIX!!,${PREFIX},' \
			-e 's,!!CVSROOT!!,${CVSROOT},' \
			-e 's,!!TITLE!!,${TITLE},' \
		${WRKSRC}/cvsweb.conf

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${CGIDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/cvsweb.cgi ${STAGEDIR}${PREFIX}/${CGIDIR}/
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/cvsweb
.for f in ${CONFFILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/etc/cvsweb/${f}.dist
.endfor
	@${MKDIR} ${STAGEDIR}${PREFIX}/${ICONSDIR}/cvsweb
	${INSTALL_DATA} ${WRKSRC}/icons/* ${STAGEDIR}${PREFIX}/${ICONSDIR}/cvsweb/
	@${MKDIR} ${STAGEDIR}${PREFIX}/${CSSDIR}/cvsweb
	${INSTALL_DATA} ${WRKSRC}/css/*.css ${STAGEDIR}${PREFIX}/${CSSDIR}/cvsweb/
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/enscript/hl
	${INSTALL_DATA} ${WRKSRC}/enscript/*.st ${STAGEDIR}${PREFIX}/share/enscript/hl/
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ChangeLog INSTALL NEWS README TODO
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/* ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.post.mk>
