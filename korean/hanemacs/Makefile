# New ports collection makefile for:	hanemacs
# Date created:		12 Mar 1998
# Whom:			CHOI Junho <junker@jazz.snu.ac.kr>
#
# $FreeBSD$
#

PORTNAME=	hanemacs
PORTVERSION=	19.34b.1
PORTREVISION=	1
CATEGORIES=	korean editors
MASTER_SITES=	ftp://ftp.kr.freebsd.org/pub/FreeBSD-kr/distfiles/ \
		ftp://ftp.kaist.ac.kr/pub/hangul/editor/HanEmacs/ \
		ftp://ftp.kreonet.re.kr/pub/hangul/cair-archive/editor/HanEmacs/
DISTNAME=	hanemacs-19.34b-1

MAINTAINER=	cjh@FreeBSD.org
COMMENT=	Korean version of GNU editing macros

NOT_FOR_ARCHS=	alpha

WRKSRC=		${WRKDIR}/hanemacs-19.34
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--with-x-toolkit \
		--sharedstatedir=/var/run
CONFIGURE_TARGET=	${MACHINE_ARCH}--freebsd
STRIP=
MAN1=		emacs.1 etags.1 ctags.1

pre-build:
	@cd ${WRKSRC}; \
	for file in \
		hanemacs.README hanemacs_manual.ks \
		hanemacs_manual.ps hanemacs_manual.txt; do \
	${CP} $$file etc/; \
	done; \
	${CP} ${FILESDIR}/site-init.el lisp/

post-install:
.for file in hanemacs-19.34 emacsclient etags ctags b2m
	strip ${PREFIX}/bin/${file}
.endfor
.for info in emacs vip viper forms gnus mh-e cl sc dired-x ediff ccmode message
	install-info ${PREFIX}/info/${info} ${PREFIX}/info/dir
.endfor
# install emacs.sh into ${PREFIX}/etc/rc.d
	${MKDIR} /var/run/emacs/lock
	${CHMOD} 1777 /var/run/emacs/lock
	@${MKDIR} ${PREFIX}/etc/rc.d
	@${INSTALL_SCRIPT} ${FILESDIR}/emacs.sh ${PREFIX}/etc/rc.d

.include <bsd.port.mk>
