# New ports collection makefile for:	hanemacs
# Version required:	19.34b-2
# Date created:		12 Mar 1998
# Whom:			CHOI Junho <junker@jazz.snu.ac.kr>
#
# $Id: Makefile,v 1.2 1998/10/16 01:12:22 jseger Exp $
#

DISTNAME=	hanemacs-19.34b-1
PKGNAME=	ko-hanemacs-19.34b1
CATEGORIES=	korean editors
MASTER_SITES=	ftp://ftp.kaist.ac.kr/pub/hangul/editor/HanEmacs/ \
		ftp://ftp.kreonet.re.kr/pub/hangul/cair-archive/editor/HanEmacs/

MAINTAINER=	junker@jazz.snu.ac.kr

WRKSRC=		${WRKDIR}/hanemacs-19.34
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	i386--freebsd --with-x-toolkit \
		--sharedstatedir=/var/run
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
	if [ ! -f ${PREFIX}/info/dir ]; then \
	  ${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	fi
.for info in emacs vip viper forms gnus mh-e cl sc dired-x ediff ccmode message
	install-info ${PREFIX}/info/${info} ${PREFIX}/info/dir
.endfor
# install emacs.sh into ${PREFIX}/etc/rc.d
	${MKDIR} /var/run/emacs/lock
	chmod 1777 /var/run/emacs/lock
	@${MKDIR} ${PREFIX}/etc/rc.d
	@${INSTALL_SCRIPT} ${FILESDIR}/emacs.sh ${PREFIX}/etc/rc.d

.include <bsd.port.mk>
