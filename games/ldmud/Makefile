# New ports collection makefile for:	ldmud
# Date created:		13 August 2003
# Whom:			glewis@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	ldmud
PORTVERSION=	3.2.9
CATEGORIES=	games net
MASTER_SITES=	http://www.bearnip.com/ftp/mud/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//g}

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	A modern version of the LPMud game driver

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--libdir=${DATADIR} --bindir=${PREFIX}/sbin
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src
ALL_TARGET=	ldmud

LOGDIR=		${DATADIR}
.if defined(MUDLIB) && ${MUDLIB} == lpmud
PLIST_SUB+=	LPMUD="" MUDLIB="@comment "
LOGDIR=		${DATADIR}/log
.elif !defined(MUDLIB) || ${MUDLIB} != none
PLIST_SUB+=	LPMUD="@comment " MUDLIB=""
.else
PLIST_SUB+=	LPMUD="@comment " MUDLIB="@comment "
.endif

post-install:
	# Install an RC script for ldmud
	${CAT} ${FILESDIR}/ldmud.sh | ${SED} -e "s:%%PREFIX%%:${PREFIX}:" \
		-e "s:%%LOGDIR%%:${LOGDIR}:" > \
		${PREFIX}/etc/rc.d/ldmud.sh.sample
	${CHMOD} a+x ${PREFIX}/etc/rc.d/ldmud.sh.sample
	# Create mudlib directory
	${MKDIR} ${DATADIR}
.if defined(MUDLIB) && ${MUDLIB} == lpmud
	cd ${WRKDIR}/${PORTNAME}-${PORTVERSION}/mud/lp-245 && ${FIND} . \
		| ${CPIO} -pdmu ${DATADIR}
.elif !defined(MUDLIB) || ${MUDLIB} != none
	cd ${WRKDIR}/${PORTNAME}-${PORTVERSION}/mudlib && ${FIND} . \
		| ${CPIO} -pdmu ${DATADIR}
.endif
	# Set mudlib ownership
	-@${CHOWN} -h -R mud:mud ${DATADIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKDIR}/${PORTNAME}-${PORTVERSION}/doc && ${FIND} . \
		| ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
	${RM} -f ${DOCSDIR}/Makefile
.endif
	# Run package install script
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGDIR}/pkg-install ${PKGNAME} \
		POST-INSTALL

.include <bsd.port.mk>
