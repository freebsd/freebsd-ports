# New ports collection makefile for:	dancer-ircd
# Date Created:		14 April 2003
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	dancer-ircd
PORTVERSION=	1.0.31m8
PORTREVISION=	1
CATEGORIES=	irc
MASTER_SITES=	http://www.doc.ic.ac.uk/~aps100/dancer/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTNAME}/stable/releases
DISTNAME=	${PORTNAME}-${PORTVERSION:S/m/+maint/}

MAINTAINER=	knu@FreeBSD.org
COMMENT=	An irc daemon based on hybrid ircd

USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

.if !defined(PACKAGE_BUILDING) && !defined(BATCH)
IS_INTERACTIVE=	yes
.endif

post-patch:
	${REINPLACE_CMD} 's:@@prefix@@:${PREFIX}:g' ${WRKSRC}/include/config.h

pre-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	${INSTALL} -d -m 700 -o ircd -g ircd \
		${PREFIX}/etc/dancer-ircd \
		/var/log/dancer-ircd \
		/var/run/dancer-ircd
	${INSTALL_DATA} ${WRKSRC}/doc/example.conf ${PREFIX}/etc/dancer-ircd/ircd.conf.sample
.for f in kline.conf dline.conf motd ohelp omotd
	${TOUCH} ${PREFIX}/etc/dancer-ircd/${f}.sample
.endfor
.for f in ircd.conf kline.conf dline.conf motd ohelp omotd
	if [ ! -f ${PREFIX}/etc/dancer-ircd/${f} ]; then \
		${CP} ${PREFIX}/etc/dancer-ircd/${f}.sample ${PREFIX}/etc/dancer-ircd/${f}; \
	fi
.endfor
	${FIND} ${PREFIX}/etc/dancer-ircd -type d -print0 | \
		${XARGS} -0 ${CHMOD} 700
	${FIND} ${PREFIX}/etc/dancer-ircd -type f -print0 | \
		${XARGS} -0 ${CHMOD} 600
	${CHOWN} -R ircd:ircd ${PREFIX}/etc/dancer-ircd
	${SED} -e "s,%PREFIX%,${PREFIX},g" ${FILESDIR}/dancer-ircd.sh \
		> ${WRKDIR}/dancer-ircd.sh
	${INSTALL_SCRIPT} ${WRKDIR}/dancer-ircd.sh ${PREFIX}/etc/rc.d/
	${SED} -e "s,/usr/local/,${PREFIX}/,g" ${PKGMESSAGE}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/doc/* ${DOCSDIR}/
.endif

.include <bsd.port.mk>
