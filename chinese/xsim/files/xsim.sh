#!/bin/sh

# Install user settings directory if it does not exist
if [ ! -d ${HOME}/.xsim ]
then
       mkdir ${HOME}/.xsim
       cp %%PREFIX%%/share/xsim/dat/* ${HOME}/.xsim/
       sed "/^DICT_LOCAL/s|%%PREFIX%%/share/xsim/dat|${HOME}/.xsim|g" \
               %%PREFIX%%/etc/xsimrc > ${HOME}/.xsim/xsimrc
fi

# Start xsim
exec %%PREFIX%%/share/xsim/bin/xsim $*
