# New ports collection makefile for:	tnftpd
# Date created:				3 August 2003
# Whom:					ports
#
# $FreeBSD$
#

PORTNAME=	tnftpd
PORTVERSION=	20080609
CATEGORIES=	ftp ipv6
MASTER_SITES=	ftp://ftp.netbsd.org/pub/NetBSD/misc/tnftp/

MAINTAINER=	cejkar@fit.vutbr.cz
COMMENT=	Enhanced ftp server from NetBSD

GNU_CONFIGURE=	yes

CFLAGS+=	-DSUPPORT_UTMP

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 900007
BROKEN=		fails to build with new utmpx
.endif

.if defined(WITH_SOCKS5)
BUILD_DEPENDS+=	${LOCALBASE}/lib/libsocks5.a:${PORTSDIR}/net/socks5
CONFIGURE_ARGS+=	--with-socks5
.endif

MAN5=		ftpd.conf.5 ftpusers.5
MAN8=		tnftpd.8
PLIST_FILES=	libexec/tnftpd
PORTDOCS=	ChangeLog NEWS README THANKS COPYING

SUB_FILES=	pkg-message
FIXPREFIX=	ftpd.8 ftpd.conf.5 ftpusers.5

pre-patch:
.for f in ${FIXPREFIX}
	${REINPLACE_CMD} -e \
		"s@^\.Dq Pa /etc@.Dq Pa ${PREFIX}/etc@g; \
		s@^\.Pa /etc@.Pa ${PREFIX}/etc@g; \
		s@^\.It Pa /etc/@.It Pa ${PREFIX}/etc/@g; \
		s@^\.Ss /etc/@.Ss ${PREFIX}/etc/@g; \
		s@^\.Sx /etc/@.Sx ${PREFIX}/etc/@g; \
		s@^\.Bl -tag -width /etc/@.Bl -tag -width ${PREFIX}/etc/@g; \
		s@${PREFIX}/etc/shells@/etc/shells@g; \
		s@${PREFIX}/etc/nologin@/etc/nologin@g; \
		s@${PREFIX}/etc/pwd.db@/etc/pwd.db@g" \
	${WRKSRC}/src/${f}
.endfor
	${REINPLACE_CMD} -e \
		"s@^#define	_DEFAULT_CONFDIR	\"/etc\"@#define	_DEFAULT_CONFDIR	\"${PREFIX}/etc\"@" \
	${WRKSRC}/src/pathnames.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/tnftpd ${PREFIX}/libexec
	${INSTALL_MAN} ${WRKSRC}/src/ftpd.8 ${PREFIX}/man/man8/tnftpd.8
	${INSTALL_MAN} ${WRKSRC}/src/ftpd.conf.5 ${PREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/src/ftpusers.5 ${PREFIX}/man/man5
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
