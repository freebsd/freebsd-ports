# ex:ts=8
# Ports collection makefile for:  svr4_base
# Version required:     	  2.6
# Date created:			  Monday Dec 25, 2000
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME=	svr4_base
PORTVERSION=	2.6
CATEGORIES=	emulators
MASTER_SITES=	# none for now
DISTFILES=	# none for now

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Compatibility framework necessary for SVR4 emulation

PREFIX=		/	# distfile tared as "/compat/svr4"
NO_MTREE=	yes
NO_BUILD=	yes
EXTRACT_ONLY=	# empty
NO_WRKSUBDIR=	yes

do-install:
.for D in dev etc/default
	@[ -d ${PREFIX}/compat/svr4/$D ] || ${MKDIR} ${PREFIX}/compat/svr4/$D
.endfor
.for F in etc/default/init etc/mnttab
	@[ -e ${PREFIX}/compat/svr4/$F ] || ${TOUCH} ${PREFIX}/compat/svr4/$F
.endfor
	@${INSTALL_DATA} ${FILESDIR}/SVR4_MAKEDEV ${PREFIX}/compat/svr4/dev
	@cd ${FILESDIR} ; \
	    ${INSTALL_DATA} netconfig nsswitch.conf ${PREFIX}/compat/svr4/etc
	@cd ${PREFIX}/compat/svr4 ; ${LN} -sf usr/lib lib
	@cd ${PREFIX}/compat/svr4 ; \
		${LN} -sf /cdrom/Solaris_2.6/Tools/Boot/usr usr
	@${INSTALL_MAN} ${FILESDIR}/README ${PREFIX}/compat/svr4

.include <bsd.port.mk>
