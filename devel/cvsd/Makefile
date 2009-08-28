# ex:ts=8
# Ports collection makefile for:	cvsd
# Date Created:			Dec 31, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	cvsd
PORTVERSION=	1.0.16
CATEGORIES=	devel
MASTER_SITES=	http://arthurdejong.org/cvsd/ \
		http://wiftp.com/

MAINTAINER=	bu7cher@yandex.ru
COMMENT=	CVS pserver daemon

EXTRA_PATCHES=	${FILESDIR}/extra-cvsd-buildroot.in

USE_PERL5=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--with-libwrap
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"

MAN5=		cvsd.conf.5
MAN8=		cvsd.8 cvsd-buginfo.8 cvsd-buildroot.8 cvsd-passwd.8
PORTDOCS=	FAQ NEWS README
PLIST_FILES=	etc/cvsd/cvsd.conf.sample sbin/cvsd sbin/cvsd-buginfo \
		sbin/cvsd-buildroot sbin/cvsd-passwd
PLIST_DIRS=	etc/cvsd
USE_RC_SUBR=	cvsd

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cvsd ${PREFIX}/sbin/cvsd
.for f in cvsd-buginfo cvsd-buildroot cvsd-passwd
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${PREFIX}/sbin
.endfor
	@${MKDIR} ${PREFIX}/etc/cvsd
	${INSTALL_DATA} ${WRKSRC}/cvsd.conf-dist ${PREFIX}/etc/cvsd/cvsd.conf.sample
.for FILE in ${MAN5}
	${INSTALL_MAN} ${WRKSRC}/${FILE} ${MAN5PREFIX}/man/man5
.endfor
.for FILE in ${MAN8}
	${INSTALL_MAN} ${WRKSRC}/${FILE} ${MAN8PREFIX}/man/man8
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for docs in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${docs} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
