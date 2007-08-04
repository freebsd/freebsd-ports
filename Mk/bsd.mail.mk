#-*- mode: Fundamental; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#
# Please view me with 4 column tabs!

.if !defined(_POSTMKINCLUDED) && !defined(Mail_Pre_Include)

# Please make sure all changes to this file are passed through the maintainer.
# Do not commit them yourself (unless of course you're the Port's Wraith ;).
Mail_Include_MAINTAINER=	garga@FreeBSD.org
Mail_Pre_Include=			bsd.mail.mk


## Begin QMAIL Stuff

# Ports can use the following vars:
#
# QMAIL_PREFIX		- Define it if qmail is installed in a different PREFIX.
#					  Default: /var/qmail
#
# QMAIL_SLAVEPORT	- Define it if you install a slaveport of qmail, to
#					  prevent stale dependencies. Valid slaveports are:
#					  ldap, mysql, spamcontrol and tls.
#
# USE_QMAIL_BUILD	- Add qmail or qmail slaveport to BUILD_DEPENDS.
#
# USE_QMAIL_RUN		- Add qmail or qmail slaveport to RUN_DEPENDS.
#
# USE_QMAIL			- Add qmail or qmail slaveport to RUN and BUILD_DEPENDS.
#
# WANT_QMAIL		- Set vars related to qmail, like QMAIL_PREFIX.

QMAIL_PREFIX?=	/var/qmail

_QMAIL_VALID_SLAVEPORTS=	ldap mysql spamcontrol tls

.if defined(USE_QMAIL) || defined(USE_QMAIL_RUN) || defined (USE_QMAIL_BUILD)

.if defined(QMAIL_SLAVEPORT)
.	for slave in ${_QMAIL_VALID_SLAVEPORTS}
.		if ${QMAIL_SLAVEPORT:L} == ${slave}
_QMAIL_SLAVEPORT_OKAY=	true
.		endif
.	endfor

.	if !defined(_QMAIL_SLAVEPORT_OKAY)
IGNORE=	Invalid QMAIL_SLAVEPORT value. Only one can be set, valid values are: ${_QMAIL_VALID_SLAVEPORTS}
.	endif
.endif

.if defined(QMAIL_SLAVEPORT)
QMAIL_DEPENDS=	${QMAIL_PREFIX}/bin/qmail-send:${PORTSDIR}/mail/qmail-${QMAIL_SLAVEPORT:L}
.else
QMAIL_DEPENDS=	${QMAIL_PREFIX}/bin/qmail-send:${PORTSDIR}/mail/qmail
.endif

.if defined(USE_QMAIL) || defined(USE_QMAIL_RUN)
RUN_DEPENDS+=	${QMAIL_DEPENDS}
.endif

.if defined(USE_QMAIL) || defined(USE_QMAIL_BUILD)
BUILD_DEPENDS+=	${QMAIL_DEPENDS}
.endif

.endif

## End QMAIL Stuff

.endif
