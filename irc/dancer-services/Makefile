# New ports collection makefile for:	dancer-services
# Date Created:		14 April 2003
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	dancer-services
PORTVERSION=	1.8.0.6.9
PORTREVISION=	1
CATEGORIES=	irc
MASTER_SITES=	http://source.freenode.net/~asuffield/dancer/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	knu@FreeBSD.org
COMMENT=	The IRC services (nickserv, chanserv, etc.) for dancer-ircd

BUILD_DEPENDS+=		${LOCALBASE}/bin/autoconf:${PORTSDIR}/devel/autoconf

USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAKE_ARGS=	BINDIR=${PREFIX}/sbin \
		CONFDIR=${PREFIX}/etc/dancer-services \
		HELPDIR=${PREFIX}/share/dancer-services/help \
		WHOAMI=root

.if !defined(PACKAGE_BUILDING) && !defined(BATCH)
IS_INTERACTIVE=	yes
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502000
BROKEN=		"Configure fails"
.endif

post-patch:
	${REINPLACE_CMD} 's:@@prefix@@:${PREFIX}:g' \
		${WRKSRC}/bin/services.conf \
		${WRKSRC}/bin/settings.conf.in

pre-configure:
	cd ${WRKSRC}; ${SH} ./autogen.sh

pre-build:
	cd ${WRKSRC}; ${MAKE} depend

pre-install:
	${MKDIR} ${PREFIX}/share/dancer-services
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	${FIND} ${PREFIX}/share/dancer-services -type d -print0 | \
		${XARGS} -0 ${CHMOD} 755
	${FIND} ${PREFIX}/share/dancer-services -type f -print0 | \
		${XARGS} -0 ${CHMOD} ${SHAREMODE}
	${INSTALL} -d -m 700 -o ircservices -g ircservices \
		/var/log/dancer-services \
		/var/run/dancer-services
.for f in motd.dcc motd.global services.conf settings.conf
	${INSTALL_DATA} ${WRKSRC}/bin/${f} ${PREFIX}/etc/dancer-services/${f}.sample
.endfor
.for f in glines.conf jupes.conf logon.news
	${TOUCH} ${PREFIX}/etc/dancer-services/${f}.sample
	if [ ! -f ${PREFIX}/etc/dancer-services/${f} ]; then \
		${CP} ${PREFIX}/etc/dancer-services/${f}.sample ${PREFIX}/etc/dancer-services/${f}; \
	fi
.endfor
	${FIND} ${PREFIX}/etc/dancer-services -type d -print0 | \
		${XARGS} -0 ${CHMOD} 700
	${FIND} ${PREFIX}/etc/dancer-services -type f -print0 | \
		${XARGS} -0 ${CHMOD} 600
	${CHOWN} -R ircservices:ircservices ${PREFIX}/etc/dancer-services
	${SED} -e "s,%PREFIX%,${PREFIX},g" ${FILESDIR}/dancer-services.sh \
		> ${WRKDIR}/dancer-services.sh
	${INSTALL_SCRIPT} ${WRKDIR}/dancer-services.sh ${PREFIX}/etc/rc.d/
	${SED} -e "s,/usr/local/,${PREFIX}/,g" ${PKGMESSAGE}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ChangeLog README
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.post.mk>
