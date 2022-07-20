PORTNAME=	cvsweb
PORTVERSION=	2.0.6
PORTREVISION=	2
CATEGORIES=	devel www
MASTER_SITES=	LOCAL/scop http://people.FreeBSD.org/~scop/cvsweb/

# For issues that are not specific to this port/package, please consult
# the <freebsd-cvsweb@FreeBSD.org> mailing list.
MAINTAINER=	noackjr@alumni.rice.edu
COMMENT=	WWW CGI script to browse CVS repository trees

CONFLICTS=	cvsweb-3.*

USES=		cpe perl5

CPE_VENDOR=	freebsd

NO_BUILD=	yes
PLIST_SUB=	CGIDIR="${CGIDIR}" ICONSDIR="${ICONSDIR}"
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS

CONFFILES=	cvsweb.conf \
		cvsweb.conf-freebsd \
		cvsweb.conf-openbsd \
		cvsweb.conf-netbsd \
		cvsweb.conf-ruby

# Specify the title of your cvsweb site.
TITLE?=		My CVS Repository

.include <bsd.port.pre.mk>

# Specify where your repository belongs.
# (You can reconfigure it after installation anyway)
.if defined(PACKAGE_BUILDING) || !defined(CVSROOT) || empty(CVSROOT)
CVSROOT=	/home/cvs
.endif

# Specify these directories in relative paths to ${PREFIX}.
.if !exists(${PREFIX}/www) && exists(${PREFIX}/share/apache)
CGIDIR?=	share/apache/cgi-bin
ICONSDIR?=	share/apache/icons
.else
CGIDIR?=	www/cgi-bin
ICONSDIR?=	www/icons
.endif

post-patch:
	@${REINPLACE_CMD} -i '' -e 's,!!PERL!!,${PERL},' \
			-e 's,!!PREFIX!!,${PREFIX},' \
		${WRKSRC}/cvsweb.cgi
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

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ChangeLog INSTALL README README.FreeBSD TODO TODO.FreeBSD
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.post.mk>
