# New ports collection makefile for:	lukemftpd
# Date created:				12 April 2001
# Whom:					Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	lukemftpd
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	ftp ipv6
MASTER_SITES=	ftp://ftp.netbsd.org/pub/NetBSD/misc/lukemftp/old/ \
		ftp://ftp.nuug.no/pub/anders/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Enhanced ftp server from NetBSD

DEPRECATED=	"lukemftpd was renamed to tnftpd"
EXPIRATION_DATE=2004-08-30
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes

DOCS=		ChangeLog README THANKS

MAN5=		ftpd.conf.5 ftpusers.5
MAN8=		ftpd.8

FIXPREFIX=	ftpd.8 ftpd.conf.5 ftpusers.5

pre-patch:
.for f in ${FIXPREFIX}
	${REINPLACE_CMD} -e "s@^\.Dq Pa /etc@.Dq Pa ${PREFIX}/etc@g; \
		s@^\.Pa /etc@.Pa ${PREFIX}/etc@g; \
		s@^\.It Pa /etc/@.It Pa ${PREFIX}/etc/@g; \
		s@^\.Ss /etc/@.Ss ${PREFIX}/etc/@g; \
		s@^\.Sx /etc/@.Sx ${PREFIX}/etc/@g; \
		s@^\.Bl -tag -width /etc/@.Bl -tag -width ${PREFIX}/etc/@g; \
		s@${PREFIX}/etc/shells@/etc/shells@g; \
		s@${PREFIX}/etc/pwd.db@/etc/pwd.db@g" \
	${WRKSRC}/src/${f}
.endfor
	${REINPLACE_CMD} -e \
		"s@^#define	_DEFAULT_CONFDIR	\"/etc\"@#define	_DEFAULT_CONFDIR	\"${PREFIX}/etc\"@" \
	${WRKSRC}/src/pathnames.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/ftpd ${PREFIX}/libexec/ftpd
	${INSTALL_MAN} ${WRKSRC}/src/ftpd.8 ${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/src/ftpd.conf.5 ${PREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/src/ftpusers.5 ${PREFIX}/man/man5
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/lukemftpd
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/lukemftpd/
.endfor
.endif

post-install:
	@${ECHO_MSG} "================================================================================"
	@${ECHO_MSG} "This port relies on a number of configuration files in ${PREFIX}/etc."
	@${ECHO_MSG} "At the very least, create a ftpusers file with the usernams of users you don't"
	@${ECHO_MSG} "want to connect (root, toor, etc.). This will allow non-listed users to log in."
	@${ECHO_MSG} "Copying /etc/ftpusers to ${PREFIX}/etc/ftpusers should be sufficient."
	@${ECHO_MSG}
	@${ECHO_MSG} "See the man files for more information. The man- and configuration files for"
	@${ECHO_MSG} "FreeBSD's built-in ftpd can also be of use as examples/additional info."
	@${ECHO_MSG} "================================================================================"

.include <bsd.port.mk>
