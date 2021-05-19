# Shared namespace for Ansible-related ports.
#
# Feature:	ansible
# Usage:	USES=ansible:ARGS
# Valid ARGS:	env, module, plugin
#
# env		The port does not depend on Ansible but needs some Ansible
#		variables set.
# module	The port is an Ansible module. (*)
# plugin	The port is an Ansible plugin. (*)
#
# (*)	See Ansible documentation to learn about the difference
#	between a module and a plugin:
#	https://docs.ansible.com/ansible/latest/dev_guide/developing_locally.html
#
# Variables for ports:
#
# ANSIBLE_CMD		- Path to the ansible program.
# ANSIBLE_DOC_CMD	- Path to the ansible-doc program.
# ANSIBLE_RUN_DEPENDS	- RUN_DEPENDS with the Ansible port.
#
# ANSIBLE_DATADIR	- Path to the root of the directory structure where all
#			  Ansible's modules and plugins are stored.
# ANSIBLE_ETCDIR	- Path to the Ansible etc directory.
# ANSIBLE_PLUGINS_PREFIX
#			- Path to the "plugins" directory
#			  within ${ANSIBLE_DATADIR}.
# ANSIBLE_MODULESDIR	- Path to the directory for local Ansible modules.
# ANSIBLE_PLUGINSDIR	- Path to the directory for local Ansible plugins.
# ANSIBLE_PLUGIN_TYPE	- Ansible plugin type (e.g., "connection", "inventory",
#			  or "vars").
#
# Other information:
# - USES=ansible implies USES=python:env automatically if no USES=python has
#   been specified yet.
#
# MAINTAINER: ports@FreeBSD.org

.if !defined(_INCLUDE_USES_ANSIBLE_Mk)
_INCLUDE_USES_ANSIBLE_Mk=	yes

_valid_ARGS=    env module plugin
.for _arg in ${ansible_ARGS}
.  if !${_valid_ARGS:M${_arg}}
IGNORE=	USES=ansible: invalid argument: ${_arg}
.  endif
.endfor
.if ${ansible_ARGS:[#]} != 1
IGNORE=	USES=ansible: too many arguments: ${ansible_ARGS}
.endif
.if empty(ansible_ARGS)
IGNORE=	USES=ansible: no arguments specified
.endif

.if !${USES:Mpython*}
python_ARGS=	env
_USES_POST+=		python:env
.include "${USESDIR}/python.mk"
.endif

ANSIBLE_CMD?=		${LOCALBASE}/bin/ansible
ANSIBLE_DOC_CMD?=	${LOCALBASE}/bin/ansible-doc
ANSIBLE_RUN_DEPENDS?=	${PYTHON_PKGNAMEPREFIX}ansible>0:sysutils/ansible@${PY_FLAVOR}

ANSIBLE_DATADIR?=		${PREFIX}/share/${PYTHON_PKGNAMEPREFIX}ansible
ANSIBLE_ETCDIR?=		${PREFIX}/etc/ansible
ANSIBLE_PLUGINS_PREFIX?=	${ANSIBLE_DATADIR}/plugins
.if ${ansible_ARGS} == "module"
ANSIBLE_MODULESDIR?=		${ANSIBLE_PLUGINS_PREFIX}/modules
.elif ${ansible_ARGS} == "plugin"
.  if empty(ANSIBLE_PLUGIN_TYPE)
IGNORE=	ANSIBLE_PLUGIN_TYPE must be set
.  endif
ANSIBLE_PLUGINSDIR?=		${ANSIBLE_PLUGINS_PREFIX}/${ANSIBLE_PLUGIN_TYPE}
.endif

.if ${ansible_ARGS} == "module" || ${ansible_ARGS} == "plugin"
RUN_DEPENDS+=	${ANSIBLE_RUN_DEPENDS}
.endif
.endif
